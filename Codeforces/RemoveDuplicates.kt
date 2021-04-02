object RemoveDuplicates {
    fun solve(){
        (readLine() to readLine()!!.split(" ").map { it.toInt() }.reversed().toSet().toList().reversed()).second.let {
            println(it.size)
            println(it.joinToString(" "))
        }
    }
}

fun main() = RemoveDuplicates.solve()