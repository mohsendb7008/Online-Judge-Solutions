fun IntArray.upperBound(x: Int): Int{
    if(x < this[0])
        return -1
    var(lo, hi) = 0 to this.size-1
    while (lo < hi){
        val mid = (lo + hi) / 2 + (lo + hi) % 2
        if(this[mid] <= x)
            lo = mid
        else
            hi = mid - 1
    }
    return lo
}

fun main(){
    val(n, m) = readLine()!!.split(" ").map{ it.toInt() }
    val doors = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val psum = IntArray(n)
    psum[0] = doors[0]
    for(i in 1 until n)
        psum[i] = psum[i-1] + doors[i]
    val q = readLine()!!.toInt()
    repeat(q){
        val humans = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        val diff = IntArray(humans.size)
        diff[0] = humans[1] - 1
        for(i in 1 until humans.size)
            diff[i] = (if(i + 1 == humans.size) m else humans[i+1] - 1) - humans[i]
        var i = 0
        for(d in diff){
            val search = (if(i == 0) 0 else psum[i-1]) + d
            i = psum.upperBound(search) + 1
        }
        println(if(i == n) "YES" else "NO")
    }
}