import java.util.*
import kotlin.collections.ArrayList

class MyPair(val first: Long, val second: Int): Comparable<MyPair>{
    override fun compareTo(other: MyPair): Int = first.compareTo(other.first)
}

object MakeItConnected {

    private fun prim(adj: Array<ArrayList<Pair<Int, Long>>>, pq: PriorityQueue<MyPair>, taken: BooleanArray, u: Int){
        taken[u] = true
        for(x in adj[u]){
            if(!taken[x.first])
                pq.add(MyPair(x.second, x.first))
        }
    }

    fun solve(){
        val(n, m) = readLine()!!.split(" ").map { it.toInt() }
        val a = readLine()!!.split(" ").map { it.toLong() }.toList()
        val adj = Array(n){ArrayList<Pair<Int, Long>>()}
        repeat(m){
            val(x, y, w) = readLine()!!.split(" ")
            adj[x.toInt()-1].add(y.toInt()-1 to w.toLong())
            adj[y.toInt()-1].add(x.toInt()-1 to w.toLong())
        }
        var (minA, minIndexA) = Long.MAX_VALUE to 0
        for(i in 0 until n)
            if(a[i] < minA){
                minA = a[i]
                minIndexA = i
            }
        for(i in 0 until n)
            if(i != minIndexA){
                adj[minIndexA].add(i to a[minIndexA] + a[i])
                adj[i].add(minIndexA to a[minIndexA] + a[i])
            }
        val pq = PriorityQueue<MyPair>()
        val taken = BooleanArray(n)
        prim(adj, pq, taken, 0)
        var ans = 0L
        while(!pq.isEmpty()){
            val p = pq.poll()
            if(taken[p.second])
                continue
            ans += p.first
            prim(adj, pq, taken, p.second)
        }
        println(ans)
    }
}

fun main() = MakeItConnected.solve()