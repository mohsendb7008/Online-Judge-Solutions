val balls = IntArray(200003){ Int.MAX_VALUE }

fun main(){
    val(n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    balls[k-1] = 0
    for(i in 0 until m){
        var(x, y) = readLine()!!.split(" ").map { it.toInt() }
        x--
        y--
        var bx = balls[y]
        if(balls[x] != Int.MAX_VALUE && balls[x] + 1 < bx)
            bx = balls[x] + 1
        var by = balls[x]
        if(balls[y] != Int.MAX_VALUE && balls[y] + 1 < by)
            by = balls[y] + 1
        balls[x] = bx
        balls[y] = by
    }
    for(i in 0 until n)
        print(if(balls[i] == Int.MAX_VALUE) "-1 " else "${balls[i]} ")
    println()
}