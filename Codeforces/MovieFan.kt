import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

data class Elem(val first: Int, val second: Int) : Comparable<Elem> {
    override fun compareTo(other: Elem): Int {
        if(first == other.first)
            return 0
        if(first < other.first)
            return -1
        return 1
    }
}

var st = IntArray(200003)
var en = IntArray(200003)
var ind = IntArray(200003)
val movies = PriorityQueue<Elem>()
val sch = IntArray(200003)

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, m) = readLine()!!.split(" ").map { it.toInt() }
        val arr = ArrayList<Pair<Int, Int>>()
        repeat(n){
            val(a, b) = readLine()!!.split(" ").map { it.toInt() }
            arr.add(a to b)
        }
        val tmp = arr.withIndex().sortedBy { it.value.first }
        st = tmp.map { it.value.first }.toIntArray()
        en = tmp.map { it.value.second }.toIntArray()
        ind = tmp.map { it.index }.toIntArray()
        var ans = 0
        var i = 0
        var day = 1
        while (true){
            if(i == n && movies.isEmpty())
                break
            while(i < n && st[i] == day){
                movies.add(
                    Elem(
                        en[i],
                        ind[i]
                    )
                )
                i++
            }
            if(movies.isEmpty()){
                if(i < n)
                    day = st[i]
                continue
            }
            var cnt = m
            while (cnt != 0 && movies.isNotEmpty()){
                cnt--
                val mov = movies.poll()
                sch[mov.second] = day
                ans = max(ans, day - mov.first)
            }
            day++
        }
        println(ans)
        for(i in 0 until n)
            print("${sch[i]} ")
        println()
    }
}