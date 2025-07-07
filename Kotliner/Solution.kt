fun swap(a: IntArray, i: Int, j: Int) {
    val tmp = a[i]
    a[i] = a[j]
    a[j] = tmp
}

fun sort(a: IntArray, l: Int, r: Int) {
    if (r <= l)
        return
    val pivot = a[l]
    print("$pivot ")
    var ls = l
    for (i in (l+1)..r) {
        if (a[i] <= pivot) {
            ls++
            swap(a, i, ls)
        }
    }
    swap(a, l, ls)
    sort(a, l, ls-1)
    sort(a, ls+1, r)
}

fun main() {
    val n = readln().toInt()
    val a = readln().split(" ").map { it.toInt() }.toIntArray()
    sort(a, 0, n-1)
    println()
}