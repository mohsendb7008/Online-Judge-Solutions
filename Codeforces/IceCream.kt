import kotlin.math.min

inline fun <T> Iterable<T>.sumByLong(selector: (T) -> Long): Long {
    var sum = 0L
    for (element in this) {
        sum += selector(element)
    }
    return sum
}

data class IceCream(val a: Long, val b: Long, val c: Long)
val iceCream = ArrayList<IceCream>()

fun main() {
    val(n, m) = readLine()!!.split(" ").map { it.toInt() }
    repeat(n){
        val(a, b, c) = readLine()!!.split(" ").map { it.toLong() }
        iceCream.add(IceCream(a, b, c))
    }
    var k = m.toLong()
    if(k < iceCream.sumByLong { it.a } || k > iceCream.sumByLong { it.b }){
        println(-1)
        return
    }
    k -= iceCream.sumByLong { it.a }
    var ans = iceCream.sumByLong { it.a * it.c }
    if(k == 0L){
        println(ans)
        return
    }
    iceCream.sortBy { it.c }
    for(ice in iceCream){
        if(k == 0L)
            break
        val buy = min(k, ice.b - ice.a)
        k -= buy
        ans += buy * ice.c
    }
    println(ans)
}