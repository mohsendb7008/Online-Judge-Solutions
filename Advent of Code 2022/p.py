import re

flow = {}
adj = {}

while True:
    try:
        groups = re.match(r"Valve (.*?) has flow rate=(.*?); tunnel[s]? lead[s]? to valve[s]? (.*)", input()).groups()
        n = groups[0]
        f = int(groups[1])
        a = groups[2].split(", ")
        flow[n] = f
        adj[n] = a
    except KeyboardInterrupt:
        break

floyd = {}

for u, a in adj.items():
    floyd[(u, u)] = 0
    for v in a:
        floyd[(u, v)] = 1

for k in flow.keys():
    for u in flow.keys():
        for v in flow.keys():
            if (u, k) in floyd and (k, v) in floyd:
                path = floyd[(u, k)] + floyd[(k, v)]
                if (u, v) not in floyd:
                    floyd[(u, v)] = path
                elif path < floyd[(u, v)]:
                    floyd[(u, v)] = path

valves = list(filter(lambda f: flow[f] > 0, flow.keys()))

dp = {}

def cdp(open, opened, minutes):
    if minutes < 2:
        return 0
    key = (open, opened, minutes)
    if key in dp:
        return dp[key]
    state = flow[valves[open]] * (minutes - 1)
    best = state
    for i, valve in enumerate(valves):
        if i == open:
            continue
        if (opened & (1 << i)) > 0:
            continue
        best = max(best, state + cdp(i, opened + (1 << open), minutes - 1 - floyd[(valves[open], valve)]))
    dp[key] = best
    return dp[key]

ans = 0
for i, valve in enumerate(valves):
    ans = max(ans, cdp(i, 0, 30 - floyd[('AA', valve)]))
print(ans)

