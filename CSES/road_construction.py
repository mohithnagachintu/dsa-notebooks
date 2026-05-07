import sys

# Increase recursion depth for deep DSU trees
sys.setrecursionlimit(200000)

class DisjointSet:
    def __init__(self):
        self.parent = {}
        self.rank = {}
        self.size = {}

    def find(self, node):
        # If node is not in parent map, initialize it
        if node not in self.parent:
            self.parent[node] = node
            self.rank[node] = 0
            self.size[node] = 1

        # Path compression: recursive find
        if node != self.parent[node]:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def unite(self, u, v, by_size=True):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return

        if by_size:
            # Union by size
            if self.size[root_u] < self.size[root_v]:
                root_u, root_v = root_v, root_u
            self.parent[root_v] = root_u
            self.size[root_u] += self.size[root_v]
        else:
            # Union by rank
            if self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            elif self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

    def connected(self, u, v):
        return self.find(u) == self.find(v)

def solve():
    # Fast I/O: Reading all input at once
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    n = int(input_data[ptr])
    m = int(input_data[ptr + 1])
    ptr += 2

    ds = DisjointSet()
    
    # Track state
    components = n
    max_size = 1
    
    # Pre-initialize nodes 1 to n
    for i in range(1, n + 1):
        ds.find(i)

    output = []
    for _ in range(m):
        u = int(input_data[ptr])
        v = int(input_data[ptr + 1])
        ptr += 2
        
        root_u = ds.find(u)
        root_v = ds.find(v)
        
        if root_u != root_v:
            components -= 1
            ds.unite(u, v)
            # Find the new root to get the combined size
            new_root = ds.find(u)
            if ds.size[new_root] > max_size:
                max_size = ds.size[new_root]
        
        # Buffer the result
        output.append(f"{components} {max_size}")

    # Join and print all results at once
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()