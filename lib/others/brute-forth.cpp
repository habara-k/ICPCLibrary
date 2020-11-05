// K^Nの全探索

vector<int> a(N+1);
while (a[N] == 0) {
    // ここでa[0] ~ a[N-1] を使って処理
    for (int i = 0; ++a[i] == K; ++i) { a[i] = 0; }
}

