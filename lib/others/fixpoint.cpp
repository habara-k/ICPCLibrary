// ラムダ再帰
// ↓の3つ目
// http://koturn.hatenablog.com/entry/2018/06/10/060000

template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
FixPoint final : private F
{
public:
  template <typename G>
  explicit constexpr FixPoint(G&& g) noexcept
    : F{std::forward<G>(g)}
  {}
 
  template <typename... Args>
  constexpr decltype(auto)
  operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
    noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif  // !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};  // class FixPoint
 
 
#if defined(__cpp_deduction_guides)
template <typename F>
FixPoint(F&&)
  -> FixPoint<std::decay_t<F>>;
#endif  // defined(__cpp_deduction_guides)
 
 
namespace
{
template <typename F>
#if !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)
#  if defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#  elif defined(_MSC_VER) && _MSC_VER >= 1700 && defined(_Check_return_)
_Check_return_
#  endif  // defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#endif  // !defined(__has_cpp_attribute) || !__has_cpp_attribute(nodiscard)
inline constexpr decltype(auto)
makeFixPoint(F&& f) noexcept
{
  return FixPoint<std::decay_t<F>>{std::forward<std::decay_t<F>>(f)};
}
}  // namespace
 
/* 例
int
main()
{
  auto result = makeFixPoint([](auto f, int n) -> int {
    return n < 2 ? n : (f(n - 1) + f(n - 2));
  })(10);
  std::cout << result << std::endl;
}
*/

/* functionを使う場合の書き方
int main() {
  auto f = std::function<int(int)> = [&](int n) {
    return n < 2 ? n : (f(n - 1) + f(n - 2));
  };
  
  auto result = f(10);
  std::cout << result << std::endl;
}

*/
