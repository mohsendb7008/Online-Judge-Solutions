import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        var(n, k) = readLine()!!.split(" ").map { it.toInt() }
        val nums = readLine()!!.split(" ").map { it.toInt() }.withIndex().sortedBy { it.value }.toMutableList()
        val diff = IntArray(n)
        for(i in n-2 downTo 0){
            if(k == 0)
                break
            val d = nums[i+1].value - nums[i].value - 1
            if(d == 0)
                continue
            val r = min(k, d)
            k -= r
            diff[i] += r
            nums[i] = IndexedValue(nums[i].index, nums[i].value + r)
        }
        if(k != 0){
            for(i in 0 until n){
                diff[i] += k / n
                if(n - 1 - i < k % n)
                    diff[i] += 1
            }
        }
        for(i in 0 until n)
            nums[i] = IndexedValue(nums[i].index, diff[i])
        println(nums.sortedBy { it.index }.map { it.value }.joinToString(" "))
    }
}