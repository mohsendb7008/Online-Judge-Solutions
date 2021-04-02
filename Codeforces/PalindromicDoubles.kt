import kotlin.math.max

data class MPair(val first: Int, val second: Int): Comparable<MPair>{
    override fun compareTo(other: MPair): Int {
        if(first == other.first)
            return other.second.compareTo(second)
        return first.compareTo(other.first)
    }
}

fun ArrayList<Int>.lowerBound(n: Int): Int{
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

object PalindromicDoubles {
    fun solve(){
        repeat(readLine()!!.toInt()){
            val n = readLine()!!.toInt()
            val a = readLine()!!.split(" ").map { it.toInt() }.toList()
            val where = Array(n+1){ArrayList<Int>()}
            for(i in 0 until n)
                where[a[i]].add(i)
            val intervals = ArrayList<MPair>()
            for(i in 1..n) {
                if(where[i].isNotEmpty())
                    intervals.add(MPair(where[i][0], -where[i][0]))
                if(where[i].size == 2) {
                    intervals.add(MPair(where[i][0], -where[i][1]))
                    intervals.add(MPair(where[i][1], -where[i][1]))
                }
            }
            intervals.sort()
            val lis = ArrayList<Int>()
            var ans = 0
            for(interval in intervals){
                val pos = lis.lowerBound(interval.second)
                if(pos == lis.size)
                    lis.add(interval.second)
                else
                    lis[pos] = interval.second
                ans = if(interval.first == -interval.second)
                    max(ans, 2 * (pos + 1) - 1)
                else
                    max(ans, 2 * (pos + 1))
            }
            println(ans)
        }
    }
}

fun main() = PalindromicDoubles.solve()