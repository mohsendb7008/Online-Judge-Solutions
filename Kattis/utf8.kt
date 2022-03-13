// UTF-8

class UTF8Type private constructor(vararg val prefixes: String){

    companion object {

        val TYPE_1 = UTF8Type("0")
        val TYPE_2 = UTF8Type("110", "10")
        val TYPE_3 = UTF8Type("1110", "10", "10")
        val TYPE_4 = UTF8Type("11110", "10", "10", "10")

        val TYPES = listOf(
            TYPE_1,
            TYPE_2,
            TYPE_3,
            TYPE_4
        )

    }

    fun matches(codes: List<String>): Boolean {
        if(codes.size != prefixes.size)
            return false
        return codes.zip(prefixes).all { it.first.startsWith(it.second) }
    }

}

fun main() {
    val n = readLine()!!.toInt()
    val lines = Array(n) { readLine()!! }.toList()
    val ans = IntArray(UTF8Type.TYPES.size)
    var ptr = 0
    runCatching {
        while (ptr < n) {
            UTF8Type.TYPES.indexOfFirst { type ->
                type.matches(lines.subList(ptr, ptr + type.prefixes.size))
            }.let { index ->
                ans[index] += 1
                ptr += UTF8Type.TYPES[index].prefixes.size
            }
        }
    }.onFailure {
        println("invalid")
    }.onSuccess {
        ans.forEach(::println)
    }
}