object BoxesPacking {

    private fun judge(sPtr: Int, objects: List<Int>, m: Int, k: Int): Boolean{
        var(need, rem) = 1 to k - objects[sPtr]
        for(i in sPtr+1 until objects.size){
            if(objects[i] <= rem)
                rem -= objects[i]
            else {
                need++
                rem = k - objects[i]
            }
        }
        return need <= m
    }

    fun solve(){
        val(n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        val objects = readLine()!!.split(" ").map { it.toInt() }.toList()
        var(lo, hi) = 0 to n-1
        while (lo < hi){
            val mid = (lo + hi) / 2
            if(judge(mid, objects, m, k))
                hi = mid
            else
                lo = mid + 1
        }
        println(n-lo)
    }
}

fun main() = BoxesPacking.solve()