fn km2nm(dist: f64) -> f64 {
    if dist < 0.0 {
        return -1.0;
    }
    dist * 0.540000
}

fn km2lm(dist: f64) -> f64 {
    if dist < 0.0 {
        return -1.0;
    }
    dist * 0.621371
}

fn main() {
    let mut input: String = String::new();

    std::io::stdin().read_line(&mut input).expect("Incorrect");
    let dist: f64 = input.trim().parse().expect("error");

    if dist < 0.0 {
        panic!("Incorrect input data");
    }

    println!("{:.3} {:.3}", km2nm(dist), km2lm(dist))
}
