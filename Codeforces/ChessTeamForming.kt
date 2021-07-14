import java.lang.Integer.max

fun List<Int>.lowerBound(n: Int): Int{
    if(isEmpty())
        return 0
    if(last() < n)
        return this.size
    var(lo, hi) = 0 to this.size-1
    while(lo < hi){
        val mid = (lo + hi) / 2
        if(this[mid] < n)
            lo = mid + 1
        else
            hi = mid
    }
    return lo
}

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val b = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val m = readLine()!!.toInt()
    val c = readLine()!!.split(" ").map { it.toInt() }
    val out = IntArray(m)
    val lMax = ArrayList<Int>()
    lMax.add(b[0] - a[0])
    for(i in 1 until n)
        lMax.add(max(lMax.last(), b[i] - a[i]))
    val rMax = ArrayList<Int>()
    rMax.add(b[n] - a[n-1])
    for(i in n-2 downTo 0)
        rMax.add(max(rMax.last(), b[i+1] - a[i]))
    rMax.reverse()
    repeat(m) { k ->
        val ptr = a.lowerBound(c[k])
        if(ptr == 0)
            out[k] = max(rMax.first(), b[0] - c[k])
        else if(ptr == n)
            out[k] = max(lMax.last(), b[n] - c[k])
        else {
            var ans = max(lMax[ptr-1], rMax[ptr])
            ans = max(ans, b[ptr] - c[k])
            out[k] = ans
        }
    }
    println(out.joinToString(separator = " "))
}