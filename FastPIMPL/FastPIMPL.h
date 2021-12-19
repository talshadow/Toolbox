#pragma once

#include <type_traits>
#include <utility>

template <typename IMPL, std::size_t OBJECT_SIZE, std::size_t OBJECT_ALIGN>
class FastPIMPL {
private:
  template <std::size_t object_size, std::size_t object_align> void validate() {
    static_assert(object_size == OBJECT_SIZE, "Wrong object size");
    static_assert(object_align == OBJECT_ALIGN, "Wrong object aligment");
  }
  IMPL *impl() noexcept { return reinterpret_cast<IMPL *>(&m_data); }
  typename std::aligned_storage<OBJECT_SIZE, OBJECT_ALIGN>::type m_data;

public:
  template <typename... ARGS>
  explicit FastPIMPL(ARGS &&... args) noexcept(
      noexcept(IMPL(std::forward<ARGS>(args)...))) {
    new (impl()) IMPL(std::forward<ARGS>(args)...);
  }

  FastPIMPL(FastPIMPL &&rhs) noexcept { *this = std::move(rhs); }

  FastPIMPL(const FastPIMPL &rhs) noexcept(noexcept(IMPL(*rhs))) {
    *this = *rhs;
  }

  FastPIMPL &operator=(FastPIMPL &&rhs) noexcept { *impl() = std::move(*rhs); }

  FastPIMPL &operator=(const FastPIMPL &rhs) noexcept(noexcept(IMPL(*rhs))) {
    if (*rhs != this) {
      new (impl()) IMPL(*rhs);
    }
    return *this;
  }

  IMPL *operator->() noexcept { return impl(); }
  const IMPL *operator->() const noexcept { return impl(); }
  IMPL &operator*() noexcept { return *impl(); }
  const IMPL &operator*() const noexcept { return *impl(); }

  ~FastPIMPL() noexcept {
    validate<sizeof(IMPL), alignof(IMPL)>();
    impl()->~IMPL();
  }
};
