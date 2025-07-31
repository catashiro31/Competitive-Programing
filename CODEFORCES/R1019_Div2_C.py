def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    b = [-1 if _ <= k else 1 for _ in a]
    # Check 1-3
    left = -1
    s = 0
    for _ in range(len(b)):
        s += b[_]
        if s <= 0:
            left = _
            break

    right = -1
    s = 0
    for _ in range(len(b)-1,-1,-1):
        s += b[_]
        if s <= 0:
            right = _
            break
    # Check 1-3
    if left != -1 and right != -1 and right-left >= 2:
        print("YES\n")
        return

    rprefix = [b[n-1]]*n
    rmax = [b[n-1]]*n
    for _ in range(n-2,-1,-1):
        rprefix[_] = rprefix[_ + 1] + b[_]
        rmax[_] = max(rmax[_ + 1],rprefix[_])
    lprefix = [b[0]] * n
    lmax = [b[0]] * n
    for _ in range(1, len(b)):
        lprefix[_] = lprefix[_ - 1] + b[_]
        lmax[_] = max(lmax[_ - 1], lprefix[_])
    # Check 1-2
    for _ in range (n-2):
        if lprefix[_] <= 0 and rprefix[_+1] <= rmax[_+2]:
            print("YES\n")
            return
    # Check 2-3
    for _ in range (n-1,1,-1):
        if rprefix[_] <= 0 and lprefix[_-1] <= lmax[_-2]:
            print("YES\n")
            return

    print("NO\n")
    return
t = int(input())
for _ in range(t):
    solve()