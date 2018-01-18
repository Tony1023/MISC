//: Playground - noun: a place where people can play

import Cocoa

var str = "Hello, playground"

var count = 0

var check = false

func trueOrFalse() -> Bool {
    count += 1
    print("Executed. Counter equals to \(count)")
    if count % 3 == 0 { return true }
    else { return false }
}

for _ in 0..<20 {
    check ||= trueOrFalse()
}
// If the first of an "OR" is true, the second is immediately ignored.

infix operator ||=: LogicalDisjunctionPrecedence
extension Bool {
    static func ||= (left: inout Bool, right: Bool) {
        left = left || right
    }
}