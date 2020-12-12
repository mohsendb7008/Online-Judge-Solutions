fun main() {
    val(n, m, k) = readLine()!!.split(" ").map{ it.toInt() }
    val wheels = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
    if(m == 1){
        println(0)
        return
    }
    wheels.sort()
    val psum = mutableListOf(wheels[0] + 0L)
    for(i in 1 until n)
        psum.add(psum.last() + wheels[i])
    var ans = Long.MAX_VALUE
    var ptr = 0
    for(i in 0 until n - m + 1){
        while (ptr < i + m / 2 && wheels[ptr + 1].toLong() * (ptr + 1 - i + 1) - psum[ptr + 1] + (if(i != 0) psum[i -1] else 0L) <= k)
            ptr++
        var lsum = wheels[ptr].toLong() * (ptr - i + 1) - psum[ptr] + (if(i != 0) psum[i - 1] else 0L)
        var rsum = psum[i + m - 1] - psum[ptr] - wheels[ptr].toLong() * (i + m - 1 - ptr)
        if(ptr < i + m / 2 && (k - lsum) / (ptr - i + 1) > 0L){
            val opt = wheels[ptr] + (k - lsum) / (ptr - i + 1)
            lsum = opt * (ptr - i  + 1) - psum[ptr] + (if(i != 0) psum[i - 1] else 0L)
            rsum = psum[i + m - 1] - psum[ptr] - opt * (i + m - 1 - ptr)
        }
        if(lsum + rsum < ans)
            ans = lsum + rsum
    }
    println(ans)
}