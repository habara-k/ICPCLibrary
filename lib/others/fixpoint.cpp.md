---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://koturn.hatenablog.com/entry/2018/06/10/060000
  bundledCode: "#line 1 \"lib/others/fixpoint.cpp\"\n// \u30E9\u30E0\u30C0\u518D\u5E30\
    \n// \u2193\u306E3\u3064\u76EE\n// http://koturn.hatenablog.com/entry/2018/06/10/060000\n\
    \ntemplate <typename F>\nclass\n#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)\n\
    [[nodiscard]]\n#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)\n\
    FixPoint final : private F\n{\npublic:\n  template <typename G>\n  explicit constexpr\
    \ FixPoint(G&& g) noexcept\n    : F{std::forward<G>(g)}\n  {}\n \n  template <typename...\
    \ Args>\n  constexpr decltype(auto)\n  operator()(Args&&... args) const\n#if !defined(__GNUC__)\
    \ || defined(__clang__) || __GNUC__ >= 9\n    noexcept(noexcept(F::operator()(std::declval<FixPoint>(),\
    \ std::declval<Args>()...)))\n#endif  // !defined(__GNUC__) || defined(__clang__)\
    \ || __GNUC__ >= 9\n  {\n    return F::operator()(*this, std::forward<Args>(args)...);\n\
    \  }\n};  // class FixPoint\n \n \n#if defined(__cpp_deduction_guides)\ntemplate\
    \ <typename F>\nFixPoint(F&&)\n  -> FixPoint<std::decay_t<F>>;\n#endif  // defined(__cpp_deduction_guides)\n\
    \ \n \nnamespace\n{\ntemplate <typename F>\n#if !defined(__has_cpp_attribute)\
    \ || !__has_cpp_attribute(nodiscard)\n#  if defined(__GNUC__) && (__GNUC__ > 3\
    \ || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)\n__attribute__((warn_unused_result))\n\
    #  elif defined(_MSC_VER) && _MSC_VER >= 1700 && defined(_Check_return_)\n_Check_return_\n\
    #  endif  // defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__\
    \ >= 4)\n#endif  // !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)\n\
    inline constexpr decltype(auto)\nmakeFixPoint(F&& f) noexcept\n{\n  return FixPoint<std::decay_t<F>>{std::forward<std::decay_t<F>>(f)};\n\
    }\n}  // namespace\n \n/* \u4F8B\nint\nmain()\n{\n  auto result = makeFixPoint([](auto\
    \ f, int n) -> int {\n    return n < 2 ? n : (f(n - 1) + f(n - 2));\n  })(10);\n\
    \  std::cout << result << std::endl;\n}\n*/\n\n/* function\u3092\u4F7F\u3046\u5834\
    \u5408\u306E\u66F8\u304D\u65B9\nint main() {\n  auto f = std::function<int(int)>\
    \ = [&](int n) {\n    return n < 2 ? n : (f(n - 1) + f(n - 2));\n  };\n  \n  auto\
    \ result = f(10);\n  std::cout << result << std::endl;\n}\n\n*/\n"
  code: "// \u30E9\u30E0\u30C0\u518D\u5E30\n// \u2193\u306E3\u3064\u76EE\n// http://koturn.hatenablog.com/entry/2018/06/10/060000\n\
    \ntemplate <typename F>\nclass\n#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)\n\
    [[nodiscard]]\n#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)\n\
    FixPoint final : private F\n{\npublic:\n  template <typename G>\n  explicit constexpr\
    \ FixPoint(G&& g) noexcept\n    : F{std::forward<G>(g)}\n  {}\n \n  template <typename...\
    \ Args>\n  constexpr decltype(auto)\n  operator()(Args&&... args) const\n#if !defined(__GNUC__)\
    \ || defined(__clang__) || __GNUC__ >= 9\n    noexcept(noexcept(F::operator()(std::declval<FixPoint>(),\
    \ std::declval<Args>()...)))\n#endif  // !defined(__GNUC__) || defined(__clang__)\
    \ || __GNUC__ >= 9\n  {\n    return F::operator()(*this, std::forward<Args>(args)...);\n\
    \  }\n};  // class FixPoint\n \n \n#if defined(__cpp_deduction_guides)\ntemplate\
    \ <typename F>\nFixPoint(F&&)\n  -> FixPoint<std::decay_t<F>>;\n#endif  // defined(__cpp_deduction_guides)\n\
    \ \n \nnamespace\n{\ntemplate <typename F>\n#if !defined(__has_cpp_attribute)\
    \ || !__has_cpp_attribute(nodiscard)\n#  if defined(__GNUC__) && (__GNUC__ > 3\
    \ || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)\n__attribute__((warn_unused_result))\n\
    #  elif defined(_MSC_VER) && _MSC_VER >= 1700 && defined(_Check_return_)\n_Check_return_\n\
    #  endif  // defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__\
    \ >= 4)\n#endif  // !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)\n\
    inline constexpr decltype(auto)\nmakeFixPoint(F&& f) noexcept\n{\n  return FixPoint<std::decay_t<F>>{std::forward<std::decay_t<F>>(f)};\n\
    }\n}  // namespace\n \n/* \u4F8B\nint\nmain()\n{\n  auto result = makeFixPoint([](auto\
    \ f, int n) -> int {\n    return n < 2 ? n : (f(n - 1) + f(n - 2));\n  })(10);\n\
    \  std::cout << result << std::endl;\n}\n*/\n\n/* function\u3092\u4F7F\u3046\u5834\
    \u5408\u306E\u66F8\u304D\u65B9\nint main() {\n  auto f = std::function<int(int)>\
    \ = [&](int n) {\n    return n < 2 ? n : (f(n - 1) + f(n - 2));\n  };\n  \n  auto\
    \ result = f(10);\n  std::cout << result << std::endl;\n}\n\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/fixpoint.cpp
  requiredBy: []
  timestamp: '2020-09-26 09:04:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/fixpoint.cpp
layout: document
redirect_from:
- /library/lib/others/fixpoint.cpp
- /library/lib/others/fixpoint.cpp.html
title: lib/others/fixpoint.cpp
---
