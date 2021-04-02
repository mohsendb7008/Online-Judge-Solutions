const val maxN = 403
const val inf = Int.MAX_VALUE

val adj = Array(maxN){ArrayList<Int>()}
val edges = HashMap<Pair<Int, Int>, Int>()

var cnt = 0
val parent = IntArray(maxN)
val preOrder = IntArray(maxN)
val next = IntArray(maxN)

fun dfs(u: Int){
    val save = cnt
    preOrder[cnt++] = u
    for(v in adj[u])
        if(v != parent[u]) {
            parent[v] = u
            dfs(v)
        }
    next[save] = cnt
}

val dp = Array(maxN){IntArray(maxN)}
val trace = Array(maxN){BooleanArray(maxN)}

var ans = inf
val ansEdges = ArrayList<Int>()

fun main(){
    val(n, k) = readLine()!!.split(" ").map { it.toInt() }
    for(i in 0 until n-1){
        val(x, y) = readLine()!!.split(" ").map { it.toInt() }
        adj[x-1].add(y-1)
        adj[y-1].add(x-1)
        edges[x-1 to y-1] = i+1
        edges[y-1 to x-1] = i+1
    }
    if(k == n){
        println(0)
        return
    }
    for(i in 0 until n){
        cnt = 0
        parent[i] = -1
        dfs(i)
        for(i in n downTo 0)
            for(k in 0 until n){
                if(i == n)
                    dp[i][k] = if(k == 0) 0 else inf
                else{
                    dp[i][k] = inf
                    trace[i][k] = false
                    if(k > 0)
                        dp[i][k] = dp[i+1][k-1]
                    if(dp[next[i]][k] != inf && 1 + dp[next[i]][k] < dp[i][k]){
                        dp[i][k] = 1 + dp[next[i]][k]
                        trace[i][k] = true
                    }
                }
            }
        if(dp[0][k] < ans){
            ans = dp[0][k]
            ansEdges.clear()
            var it = 0
            var p = k
            while(it < n){
                if(trace[it][p]){
                    ansEdges.add(edges[preOrder[it] to parent[preOrder[it]]]!!)
                    it = next[it]
                }
                else {
                    it++
                    p--
                }
            }
        }
    }
    println(ans)
    println(ansEdges.joinToString(separator = " "))
}