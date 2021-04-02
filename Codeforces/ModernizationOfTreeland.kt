import java.util.*
import kotlin.collections.HashSet

const val maxn = 300003

val adj = Array<HashSet<Int>>(maxn){ HashSet() }
val queue = LinkedList<Int>()
var l = 0

fun dfs(u: Int, p: Int){
    if(adj[u].size == 1) {
        queue.add(u)
        l++
    }
    for(v in adj[u])
        if(v != p)
            dfs(v, u)
}

val present = BooleanArray(maxn)

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k) = readLine()!!.split(" ").map { it.toInt() }
        for(i in 0 until n)
            adj[i].clear()
        queue.clear()
        l = 0
        repeat(n-1){
            val(x, y) = readLine()!!.split(" ").map { it.toInt() }
            adj[x-1].add(y-1)
            adj[y-1].add(x-1)
        }
        if(k == 1){
            println("Yes\n1\n1")
            return@repeat
        }
        if(n == 2){
            println("Yes\n2\n1 2")
            return@repeat
        }
        dfs(0, -1)
        if(k > l){
            println("No")
            return@repeat
        }
        var del = l - k
        var cnt = n
        present.fill(true, 0, n)
        while(del != 0){
            val u = queue.pollFirst()
            present[u] = false
            cnt--
            val p = adj[u].first()
            adj[p].remove(u)
            if(adj[p].size == 1)
                queue.add(p)
            else
                del--
        }
        println("Yes\n$cnt")
        for(i in 0 until n)
            if(present[i])
                print("${i+1} ")
        println()
    }
}