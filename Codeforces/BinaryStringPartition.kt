fun List<Int>.lowerBound2(n: Int): Int{
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
    val s = readLine()!!
    val out = IntArray(s.length)
    val(zList, oList) = ArrayList<Int>() to ArrayList<Int>()
    for(i in s.indices){
        if(s[i] == '0')
            zList.add(i)
        else
            oList.add(i)
    }
    for(k in 1..s.length) {
        var ans = 1
        var(zPtr, oPtr) = 0 to 0
        while(zPtr + k < zList.size && oPtr + k < oList.size) {
            ans++
            if(zList[zPtr + k] > oList[oPtr + k]) {
                zPtr += k
                oPtr = oList.lowerBound2(zList[zPtr])
            }
            else {
                oPtr += k
                zPtr = zList.lowerBound2(oList[oPtr])
            }
        }
        out[k-1] = ans
    }
    println(out.joinToString(separator = " "))
}