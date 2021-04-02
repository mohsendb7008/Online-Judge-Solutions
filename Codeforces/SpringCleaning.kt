var arr = LongArray(200003)
var psum = LongArray(200003)

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k, x, y) = readLine()!!.split(" ").map { it.toInt() }
        arr = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
        arr.sort()
        if(arr.last() <= k){
            println(0)
            return@repeat
        }
        psum[0] = arr[0]
        for(i in 1 until n)
            psum[i] = psum[i-1] + arr[i]
        var ans = Int.MAX_VALUE
        if(psum[n-1] / n + (if(psum[n-1] % n != 0L) 1 else 0) <= k)
            ans = y
        for(i in 0 until n){
            var curr = (n - i) * x
            if(i > 0 && (psum[i-1] / n + (if(psum[i-1] % n != 0L) 1 else 0) > k))
                break
            if(i > 0 && arr[i-1] > k)
                curr += y
            if(curr < ans)
                ans = curr
        }
        println(ans)
    }
}