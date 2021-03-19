// Nasty Hacks

fun main() {
    val n = readLine()?.toInt()?:0
    repeat(n){
        val(a, b, c) = readLine()?.split(" ")?.map{ it.toInt()}?:listOf(0, 0, 0)
        println(if(a < b - c) "advertise" else if(a == b-c) "does not matter" else "do not advertise")
    }
}
