def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    c = [False]*(n+1)
    l, r = 0,int(1e10)
    kq = -1
    while l <= r:
        m = int((l+r)/2)
        sl = 0
        cur_mex = 0
        for val in a:
            if val <= n:
                c[val] = True
            while c[cur_mex] == True:
                cur_mex += 1
            if cur_mex >= m:
                sl += 1
                for _ in range(min(m+1,n+2)):
                    c[_] = False
                cur_mex = 0

        if sl < k:
            r = m-1
        else:
            kq = max(kq,m)
            l = m+1
    print(f"{kq}\n")
t = int(input())
for _ in range(t):
    solve()