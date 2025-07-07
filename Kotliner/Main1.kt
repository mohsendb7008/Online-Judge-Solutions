fun main() {
    // println("\\x" + "Hello Code Star 1404, I'm Back!".map { it.code.toHexString().drop(6) }.joinToString("\\x"))
    repeat(readln().toInt()) {
        val number = readln()
        if (number.startsWith("09") && number.length == 11 && number.all { it.isDigit() }) {
            println("+98${number.drop(1)}")
        }
        else if (number.startsWith("98") && number.length == 12 && number.all { it.isDigit() }) {
            println("+${number}")
        }
        else if (number.startsWith("+98") && number.length == 13 && number.drop(1).all { it.isDigit() }) {
            println(number)
        }
        else {
            println("invalid")
        }
    }
}