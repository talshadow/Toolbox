#pragma once
#include <string_view>

namespace deteils_logger_helper {

using StringView = std::string_view;

constexpr inline StringView::const_iterator
space_function_start_position(const StringView &str,
                              StringView::const_iterator endpos) {
  auto make_decision_according_symbol = [](StringView::const_iterator &it,
                                           int &count) -> bool {
    const auto symbol = *it;
    count += symbol == ':' ? 1 : 0;
    count == 2 && symbol == '}' ? ++count, it += 2 : nullptr;
    count > 2 ? it++ : nullptr;
    symbol == ' ' ? it++ : nullptr;
    return count > 2 || symbol == ' ';
  };

  auto find_delimiter = [&](StringView::const_iterator end,
                            int count) -> StringView::const_iterator {
    auto pos = end;
    for (; pos != str.begin() && !make_decision_according_symbol(pos, count);
         --pos) {
    }
    return pos;
  };

  return find_delimiter(endpos, 0);
}

constexpr inline StringView::const_iterator
arguments_starts_position(const StringView &str) {
  auto accept = [](StringView::const_iterator it,
                   StringView::value_type &previous) -> bool {
    const auto symbol = *it;
    const auto prev = previous;
    previous = symbol;
    return symbol == '(' && prev != '<';
  };
  auto pos = str.begin();
  for (auto previos = StringView::value_type();
       pos != str.end() && !accept(pos, previos); ++pos) {
  }
  return pos;
}

} // namespace deteils_logger_helper

constexpr inline const deteils_logger_helper::StringView
space_and_function(const deteils_logger_helper::StringView &&str) {
  const auto &end = deteils_logger_helper::arguments_starts_position(str);
  const auto &start =
      deteils_logger_helper::space_function_start_position(str, end);
  return deteils_logger_helper::StringView(start, end - start);
}

#define SPACE_AND_FUNCTION space_and_function(__PRETTY_FUNCTION__)
