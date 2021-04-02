import kotlin.collections.ArrayList
import kotlin.collections.HashSet

var n = 0
val intervals = Array(2003){0 to 0}
val tmp = HashSet<Int>()
val points = ArrayList<Int>()

fun count(start: Int, end: Int): Int{
    var cnt = 0
    for(i in 0 until n)
        if(start >= intervals[i].first && end <= intervals[i].second)
            cnt++
    return cnt
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        n = readLine()!!.toInt()
        tmp.clear()
        repeat(n){
            val(a, b) = readLine()!!.split(" ").map { it.toInt() }
            intervals[it] = a to b
            tmp.add(a)
            tmp.add(b)
        }
        points.clear()
        for(i in tmp){
            val ans = count(i, i)
            if(ans == 1){
                println(i)
                return@repeat
            }
            points.add(i)
        }
        points.sort()
        for(i in 0 until points.size-1){
            val s = points[i] + 1
            val e = points[i+1] - 1
            if(s > e)
                continue
            val ans = count(s, e)
            if(ans == 1){
                println(s)
                return@repeat
            }
        }
        println(-1)
    }
}