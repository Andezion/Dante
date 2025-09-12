fn toRadian(a: f32) -> f32 {
    a * std::f32::consts::PI / 180.0
}

fn toDegree(a: f32) -> f32 {
    a * 180.0 / std::f32::consts::PI
}

fn main() {
    let mut input = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("err");
    let what: i32 = input.trim().parse().expect("err");
    if what == 1 {
        input.clear();
        println!("Enter: ");
        std::io::stdin().read_line(&mut input).expect("err");
        let kat: f32 = input.trim().parse().expect("err");
        println!("{}", toRadian(kat));
    }
    else if what == 2 {
        input.clear();
        println!("Enter: ");
        std::io::stdin().read_line(&mut input).expect("err");
        let kat: f32 = input.trim().parse().expect("err");
        println!("{}", toDegree(kat));
    }
    else {
        panic!("err");
    }
}
