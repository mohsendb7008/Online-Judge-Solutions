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
    for(i in 0 until n - m + 1){
        var(lo, hi) = i to i + m / 2
        while(lo < hi){
            val mid = (lo + hi) / 2 + (lo + hi) % 2
            if(wheels[mid].toLong() * (mid - i + 1) - psum[mid] + (if(i != 0) psum[i - 1] else 0L) <= k)
                lo = mid
            else
                hi = mid - 1
        }
        var lsum = wheels[lo].toLong() * (lo - i + 1) - psum[lo] + (if(i != 0) psum[i - 1] else 0L)
        var rsum = psum[i + m - 1] - psum[lo] - wheels[lo].toLong() * (i + m - 1 - lo)
        if(lo < i + m / 2 && (k - lsum) / (lo - i + 1) > 0L){
            val opt = wheels[lo] + (k - lsum) / (lo - i + 1)
            lsum = opt * (lo - i  + 1) - psum[lo] + (if(i != 0) psum[i - 1] else 0L)
            rsum = psum[i + m - 1] - psum[lo] - opt * (i + m - 1 - lo)
        }
        if(lsum + rsum < ans)
            ans = lsum + rsum
    }
    println(ans)
}