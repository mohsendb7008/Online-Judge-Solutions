import kotlin.math.min

val color = IntArray(200003)
val edges = Array(200003){ Triple(0, 0, 0) }

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, m) = readLine()!!.split(" ").map { it.toInt() }
        color.fill(0, 0, n)
        for(i in 0 until m){
            val(x, y, w) = readLine()!!.split(" ").map { it.toInt() }
            edges[i] = Triple(x-1, y-1, w)
            if(w > color[x-1])
                color[x-1] = w
            if(w > color[y-1])
                color[y-1] = w
        }
        var ans = true
        for(i in 0 until m)
            if(min(color[edges[i].first], color[edges[i].second]) != edges[i].third){
                ans = false
                break
            }
        println(if(ans) "YES" else "NO")
        if(ans){
            for(i in 0 until n)
                print("${color[i]} ")
            println()
        }
    }
}