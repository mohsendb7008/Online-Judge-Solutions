import kotlin.math.max

val line = ArrayList<Triple<Int, Int, Int>>()
val seg = IntArray(100003)

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        line.clear()
        val n = readLine()!!.toInt()
        for(i in 0 until n){
            val(l, r) = readLine()!!.split(" ").map { it.toInt() }
            line.add(Triple(l, r, i))
        }
        line.sortBy { it.first }
        var switch = false
        var last = line[0].second
        seg[line[0].third] = 1
        for(i in 1 until n){
            if(!switch && line[i].first > last)
                switch = true
            seg[line[i].third] = if(switch) 2 else 1
            last = max(last, line[i].second)
        }
        if(!switch)
            println(-1)
        else{
            for(i in 0 until n)
                print("${seg[i]} ")
            println()
        }
    }
}