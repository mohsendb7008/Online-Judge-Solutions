import kotlin.math.min

val rating = IntArray(1000003){0}

fun main() {
    val(_, a, b, k) = readLine()!!.split(" ").map { it.toInt() }
    val line = readLine()!!.split(" ").map { it.toInt() }
    for(x in line)
        rating[x]++
    var ans = 0
    if(a > b){
        for(i in 1..1000000)
            if(rating[i] != 0 && i * k <= 1000000 && rating[i * k] != 0){
                val group = min(rating[i] / a, rating[i * k] / b)
                ans += group
                rating[i * k] -= b * group
            }
    }
    else{
        for(i in 1000000 downTo 1)
            if(rating[i] != 0 && i % k == 0 && rating[i / k] != 0){
                val group = min(rating[i / k] / a, rating[i] / b)
                ans += group
                rating[i / k] -= a * group
            }
    }
    println(ans)
}