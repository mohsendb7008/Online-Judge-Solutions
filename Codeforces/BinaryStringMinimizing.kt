import kotlin.math.min

fun main() {
    val q = readLine()!!.toInt()
    repeat(q){
        val line = readLine()!!.split(" ")
        val n = line[0].toInt()
        var k = line[1].toLong()
        val str = readLine()!!.toMutableList()
        var ones = 0L
        for(i in str.indices){
            if(str[i] == '1')
                ones++
            else{
                val j = i - min(ones, k).toInt()
                val tmp = str[i]
                str[i] = str[j]
                str[j] = tmp
                k -= min(ones, k)
            }
        }
        println(str.joinToString(separator = ""))
    }
}