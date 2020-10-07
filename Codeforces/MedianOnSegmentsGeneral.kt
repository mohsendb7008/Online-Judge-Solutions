var nums = IntArray(0)

fun medianGreaterOrEqualThan(m: Int): Long{
    var ans = 0L
    val table = IntArray(nums.size * 2 + 1)
    var ptr = 0
    var sum = 0
    for(i in nums.indices){
        if(nums[i] >= m){
            ptr++
            table[nums.size + ptr]++
            ans += sum + if(ptr > 0) 1 else 0
            sum += table[nums.size + ptr]
        }else{
            sum -= table[nums.size + ptr]
            ptr--
            table[nums.size + ptr]++
            sum++
            ans += sum - table[nums.size + ptr] + if(ptr > 0) 1 else 0
        }
    }
    return ans
}

fun main() {
    val m = readLine()!!.split(" ")[1].toInt()
    nums = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    println(medianGreaterOrEqualThan(m) - medianGreaterOrEqualThan(m + 1))
}