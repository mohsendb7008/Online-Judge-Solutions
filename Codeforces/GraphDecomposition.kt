import kotlin.collections.ArrayList
import java.util.TreeSet

val E = Array(200003){0 to 0}
val deg = Array(200003){ TreeSet<Int>() }
val selfC = IntArray(200003){0}
val Euler = ArrayList<Int>()

fun dfS(node: Int){
    while(deg[node].isNotEmpty()){
        val e = deg[node].pollLast()!!
        val other = if(E[e].first == node) E[e].second else E[e].first
        if(other != node)
            deg[other].remove(e)
        dfS(other)
    }
    Euler.add(node)
}

val seq = ArrayList<Int>()
val set = TreeSet<Int>()
val cycles = ArrayList<ArrayList<Int>>()

fun main() {
    val(n, m) = readLine()!!.split(" ").map { it.toInt() }
    for(i in 0 until m){
        val(x, y) = readLine()!!.split(" ").map { it.toInt() }
        E[i] = x - 1 to y - 1
        deg[x-1].add(i)
        deg[y-1].add(i)
        if(x-1 == y-1)
            selfC[x-1]++
    }
    for(i in 0 until n)
        if((deg[i].size + selfC[i]) % 2 == 1){
            println("NO")
            return
        }
    for(i in 0 until n)
        if(deg[i].isNotEmpty())
            dfS(i)
    for(node in Euler){
        if(node !in set){
            seq.add(node)
            set.add(node)
        }
        else{
            val cycle = ArrayList<Int>()
            cycle.add(node)
            while(seq.last() != node){
                val it = seq.last()
                cycle.add(it)
                seq.removeAt(seq.lastIndex)
                set.remove(it)
            }
            cycle.add(node)
            cycles.add(cycle)
        }
    }
    println("YES")
    println(cycles.size)
    for(cycle in cycles)
        println("${cycle.size} ${cycle.map{ it + 1}.joinToString(separator = " ")}")
}