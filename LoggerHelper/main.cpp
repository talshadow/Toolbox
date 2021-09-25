#include "LoggerHelper.hpp"
#include <iostream>
#include <utility>
#include <vector>

void check() {

  std::vector<std::pair<std::string, std::string>> data = {
      {"typename std::enable_if<(! std::is_void<typename "
       "mistery::internal::TypeTraitsHelper::member_return_type<Functor>::type>"
       "::value), boost::optional<typename mistery::internal::TypeTrait"
       "sHelper::member_return_type<Functor>::type> >::type "
       "mistery::internal::CoreImplGuard::cal"
       "l_runtime(Functor, ARGSTYPE&& ...) [with Functor = bool "
       "(mistery::internal::RuntimeImpl::*)(mistery"
       "::internal::ShutdownCallback*); ARGSTYPE = "
       "{mistery::internal::SystemInformationImpl*}; typen"
       "ame std::enable_if<(! std::is_void<typename "
       "mistery::internal::TypeTraitsHelper::member_re"
       "turn_type<Functor>::type>::value)",
       "CoreImplGuard::call_runtime"},
      {"set_collision_style_index", "set_collision_style_index"},
      {"set_collision_style_index()", "set_collision_style_index"},
      {"open_space::RET open_space::Guru::init(open_space::uint32, "
       "open_space::CGuruDB*, const open_space::example::Map"
       "DB*, const GCHARU*, bool, "
       "std::shared_ptr<open_space::UndergroundLineLoaderDerived>, const "
       "UndergroundLineLoaderOptions&)",
       "Guru::init"},
      {"void external::{anonymous}::anonymous_function()",
       "anonymous_function"},
      {"external::{anonymous}::include_lambda()::<lambda()>", "include_lambda"},
      {"external::SomeClass::include_lambda()::<lambda()>",
       "SomeClass::include_lambda"},
      {"virtual void Logging_MakeClassFunctionName_Test::TestBody()",
       "Logging_MakeClassFunctionName_Test::TestBody"}};

  for (const auto &record : data) {
    const auto &compare_string = space_and_function(record.first);
    if (compare_string == record.second) {
      std::cout << "PASSED\nbefore\n"
                  << record.first
                  <<"\nafter\n" << compare_string <<'\n' <<std::endl;
    } else {
      std::cout << "FAILED: expected\n"
                << '\'' << record.second << '\''
                << " size: " << record.second.size() << "\nvalue: \n"
                << '\'' << compare_string << '\''
                << " size: " << compare_string.size() << "\n"
                << "\"" << record.first << "\"" << std::endl;
    }
  }
}

int main() {
  std::cout << SPACE_AND_FUNCTION << std::endl;
  check();
  return 0;
}
