---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5024\u306E\u633F\u5165\u3092\u884C\u3046. O(log n)"
    links:
    - https://arc033.contest.atcoder.jp/tasks/arc033_3
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: randomized_binary_search_tree.cpp:\
    \ line -1: no such header\n"
  code: "#include \"./randomized_binary_search_tree.cpp\"\n\n/**\n * @brief\n * \u5E38\
    \u306B\u6607\u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u305F\u914D\u5217\uFF08\
    \u30DE\u30EB\u30C1\u30BB\u30C3\u30C8\uFF09\n * \u4EFB\u610F\u7B87\u6240\u306E\u8981\
    \u7D20\u306E\u66F4\u65B0\u30FB\u53D6\u5F97\u30FB\u633F\u5165\u30FB\u524A\u9664\
    \u3092O(log n)\u3067\u884C\u3046.\n * \u6607\u9806\u3092\u4FDD\u3063\u305F\u307E\
    \u307E\u5024\u306E\u633F\u5165\u30FB\u524A\u9664\u3092O(log n)\u3067\u884C\u3046\
    .\n * @author habara-k\n * @date 2020/05/05\n * @details verify: https://arc033.contest.atcoder.jp/tasks/arc033_3\n\
    \ */\n\ntemplate<typename T>\nstruct MultiSet : RandomizedBinarySearchTree<T>\
    \ {\n    using RBST = RandomizedBinarySearchTree<T>;\n    using Node = typename\
    \ RBST::Node;\n\n    MultiSet() : RBST() {}\n\n    /**\n    * @brief \u5024\u306E\
    \u633F\u5165\u3092\u884C\u3046. O(log n)\n    * @param[in] key: \u8981\u7D20\u306E\
    \u5024\n    */\n    void insert_key(const T& key) {\n        RBST::insert(lower_bound(this->root,\
    \ key), key);\n    }\n\n    /**\n    * @brief \u5024\u306E\u524A\u9664\u3092\u884C\
    \u3046. O(log n)\n    * @param[in] key: \u8981\u7D20\u306E\u5024\n    */\n   \
    \ void erase_key(const T& key) {\n        if (count(this->root, key) == 0) return;\n\
    \        RBST::erase(lower_bound(this->root, key));\n    }\n\nprivate:\n    int\
    \ lower_bound(Node *t, const T& key) {\n        if (!t) return 0;\n        if\
    \ (key <= t->data) return lower_bound(t->lch, key);\n        return lower_bound(t->rch,\
    \ key) + RBST::size(t->lch) + 1;\n    }\n\n    int upper_bound(Node *t, const\
    \ T& key) {\n        if (!t) return 0;\n        if (key < t->data) return upper_bound(t->lch,\
    \ key);\n        return upper_bound(t->rch, key) + RBST::size(t->lch) + 1;\n \
    \   }\n\n    int count(Node *t, const T& key) {\n        return upper_bound(t,\
    \ key) - lower_bound(t, key);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/structure/multi_set.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/multi_set.cpp
layout: document
redirect_from:
- /library/lib/structure/multi_set.cpp
- /library/lib/structure/multi_set.cpp.html
title: "\u5024\u306E\u633F\u5165\u3092\u884C\u3046. O(log n)"
---
