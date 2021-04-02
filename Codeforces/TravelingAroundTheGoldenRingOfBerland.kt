fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
    var(maxValue, maxIndex) = -1L to -1
    for(i in 0 until n){
        if(a[i] >= maxValue) {
            maxValue = a[i]
            maxIndex = i
        }
    }
    println(maxValue * n - (n - 1 - maxIndex))
}