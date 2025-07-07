fun main() {
    val n = readln().toInt()
    val numbers = readln().split(" ").map { it.toLong() }.toLongArray()
    numbers.sort()
    val lSum = LongArray(n)
    lSum[0] = numbers[0]
    for (i in 1..<n) {
        lSum[i] = lSum[i-1] + numbers[i]
    }
    val rSum = LongArray(n)
    rSum[n-1] = numbers[n-1]
    for (i in n-2 downTo 0) {
        rSum[i] = rSum[i+1] + numbers[i]
    }
    var ans = Long.MAX_VALUE
    var bestDiff = Long.MAX_VALUE
    for (i in 0..<n) {
        val lCount = i.toLong()
        val rCount = (n-i-1).toLong()
        val lDiff = if (lCount > 0) lCount * numbers[i] - lSum[i-1] else 0L
        val rDiff = if (rCount > 0) rSum[i+1] - rCount * numbers[i] else 0L
        val diff = lDiff + rDiff
        if (diff < bestDiff) {
            ans = numbers[i]
            bestDiff = diff
        }
    }
    println("$ans $bestDiff")
}