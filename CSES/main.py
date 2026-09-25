import sys


class FenwickTree:
    def __init__(self, n):
        self.bit = [0] * (n + 1)
        self.n = n

    def update(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += (i & -i)

    def query(self, i):
        total = 0
        while i > 0:
            total += self.bit[i]
            i -= (i & -i)
        return total

    def range_query(self, l, r):
        return self.query(r) - self.query(l - 1)


data = list(map(int, sys.stdin.buffer.read().split()))
n, q = data[0], data[1]
arr = [0] + data[2 : 2 + n]
fenwick_tree = FenwickTree(n)

for i in range(1, n+1):
    diff = arr[i] - arr[i-1]
    fenwick_tree.update(i, diff)

ans = []
index = 2 + n
for _ in range(q):
    op = data[index]
    if op == 1:
        a,b,u = data[index + 1], data[index + 2], data[index + 3]
        index += 4
        fenwick_tree.update(a,u)
        fenwick_tree.update(b+1,-u)
    else:
        k = data[index + 1]
        index += 2
        ans.append(str(fenwick_tree.query(k)))

print("\n".join(ans))