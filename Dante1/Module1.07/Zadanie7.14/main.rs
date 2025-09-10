fn distance(x1: i32, y1: i32, x2: i32 , y2: i32) -> f32 {
    if x1== x2 && y1 == y2 {
        return -1.0;
    }

    f32::sqrt(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) as f32)
}

fn perimeter(a: f32, b: f32, c: f32) -> f32 {
    if a + b < c || a + c < b || b + c < a {
        return -1.0;
    }
    a + b + c
}

fn area(a: f32, b: f32, c: f32) -> f32 {
    if a + b > c && b + c > a && c + a > b {
        let p: f32 = perimeter(a, b, c) / 2.0;
        return f32::sqrt(p * (p - a) * (p - b) * (p - c));
    }
    -1.0
}

fn main() {
    let mut input: String = String::new();
    println!("Enter x1 y1: ");
    std::io::stdin().read_line(&mut input).expect("err");
    let storage_x: Vec<_> = input.trim().split_whitespace().collect();
    let x1: i32 = storage_x[0].parse().expect("err");
    let y1: i32 = storage_x[1].parse().expect("err");

    let mut input1: String = String::new();
    println!("Enter x2 y2: ");
    std::io::stdin().read_line(&mut input1).expect("err");
    let storage_y: Vec<_> = input1.trim().split_whitespace().collect();
    let x2: i32 = storage_y[0].parse().expect("err");
    let y2: i32 = storage_y[1].parse().expect("err");

    let mut input2: String = String::new();
    println!("Enter x3 y3: ");
    std::io::stdin().read_line(&mut input2).expect("err");
    let storage_z: Vec<_> = input2.trim().split_whitespace().collect();
    let x3: i32 = storage_z[0].parse().expect("err");
    let y3: i32 = storage_z[1].parse().expect("err");

    let a: f32 = distance(x1, y1, x2, y2);
    let b: f32 = distance(x2, y2, x3, y3);
    let c: f32 = distance(x3, y3, x1, y1);

    let result: f32 = area(a, b, c);
    if result == -1.0 {
        panic!("Incorrect input");
    }
    println!("{:.2}", result)
}
