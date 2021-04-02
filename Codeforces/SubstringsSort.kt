import java.util.*
import kotlin.collections.ArrayList

fun String.isSubstringOf(other: String): Boolean{
    for(i in 0 until other.length - this.length + 1)
        if(other.substring(i, i + this.length) == this) {
            return true
        }
    return false
}

object SubstringsSort {
    fun solve(){
        val strings = Array(readLine()!!.toInt()){ readLine()!!}.groupingBy { it }.eachCount().toList()
        val n = strings.size
        val adj = Array(n){ArrayList<Int>()}
        val inDegree = IntArray(n)
        for(i in 0 until n)
            for(j in 0 until n)
                if(i != j && strings[i].first.isSubstringOf(strings[j].first)) {
                    adj[i].add(j)
                    inDegree[j]++
                }
        val kahn = LinkedList<Int>()
        val topologicalSort = ArrayList<Int>()
        for(i in 0 until n)
            if(inDegree[i] == 0)
                kahn.push(i)
        while(kahn.isNotEmpty()){
            if(kahn.size > 1)
                break
            val u = kahn.pollFirst()
            topologicalSort.add(u)
            for(v in adj[u]){
                inDegree[v]--
                if(inDegree[v] == 0)
                    kahn.push(v)
            }
        }
        if(topologicalSort.size < n)
            println("NO")
        else{
            println("YES")
            for(i in topologicalSort)
                repeat(strings[i].second){
                    println(strings[i].first)
                }
        }
    }
}

fun main() = SubstringsSort.solve()