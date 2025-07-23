pub enum OperationsT {
    OpAdd = 0,
    OpSub = 1,
    OpDiv = 2,
    OpMul = 3
}

pub fn add_int(a: i32, b: i32) -> i32 {
    a + b
}
pub fn sub_int(a: i32, b: i32) -> i32 {
    a - b
}
pub fn mul_int(a: i32, b: i32) -> i32 {
    a * b
}
pub fn div_int(a: i32, b: i32) -> i32 {
    if b == 0 {
        return 0;
    }
    a / b
}

pub fn calculate(a: i32, b: i32, f: fn(i32, i32) -> i32) -> i32 {
    f(a, b)
}

pub fn get_function(op: i32) -> fn(i32, i32) -> i32 {
    if op == 0 {
        return add_int;
    }
    else if op == 1 {
        return sub_int;
    }
    else if op == 2 {
        return mul_int;
    }
    div_int
}
