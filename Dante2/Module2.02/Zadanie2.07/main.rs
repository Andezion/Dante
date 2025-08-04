#[derive(Default)]
struct ComplexT {
    pub re: f32,
    pub im: f32
}

fn main() {
    let mut input: String = String::new();

    input.clear();
    println!("Enter re: ");
    std::io::stdin().read_line(&mut input).expect("Error ar re");
    let re1: f32 = input.trim().parse().expect("Error at parse");

    input.clear();
    println!("Enter char: ");
    std::io::stdin().read_line(&mut input).expect("Error ar char");
    let oper1: char = input.trim().parse().expect("Error at parse");

    input.clear();
    println!("Enter im: ");
    std::io::stdin().read_line(&mut input).expect("Error ar im");
    let mut im1: f32 = input.trim().parse().expect("Error at parse");

    if (oper1 != '-' && oper1 != '+') || im1 < 0.0 {
        panic!("Incorrect input");
    }

    input.clear();
    println!("Enter re: ");
    std::io::stdin().read_line(&mut input).expect("Error ar re");
    let re2: f32 = input.trim().parse().expect("Error at parse");

    input.clear();
    println!("Enter char: ");
    std::io::stdin().read_line(&mut input).expect("Error ar char");
    let oper2: char = input.trim().parse().expect("Error at parse");

    input.clear();
    println!("Enter im: ");
    std::io::stdin().read_line(&mut input).expect("Error ar im");
    let mut im2: f32 = input.trim().parse().expect("Error at parse");

    if (oper2 != '-' && oper2 != '+') || im2 < 0.0 {
        panic!("Incorrect input");
    }

    let mut cp1: ComplexT = Default::default();
    let mut cp2: ComplexT = Default::default();

    if oper1 == '-' {
        im1 = -1.0 * im1;
        set(&mut cp1, re1, im1);
        show(&cp1);
    }
    else {
        set(&mut cp1, re1, im1);
        show(&cp1);
    }

    println!();

    if oper2 == '-' {
        im2 = -1.0 * im2;
        set(&mut cp2, re2, im2);
        show(&cp2);
    }
    else {
        set(&mut cp2, re2, im2);
        show(&cp2);
    }

    let module1: f32 = complex_abs(&cp1);
    let module2: f32 = complex_abs(&cp2);

    if module1 > module2 {
        print!("FIRST");
    }
    else if module1 == module2 {
        print!("EQUAL");
    }
    else {
        print!("SECOND");
    }
}

fn set(cp: &mut ComplexT, re: f32, im: f32) -> &mut ComplexT {
    cp.re = re;
    cp.im = im;

    cp
}

fn show(cp: & ComplexT) {
    if cp.im < 0.0 {
        println!("{:.2} - i{:.2}", cp.re, f32::abs(cp.im));
    }
    else {
        println!("{:.2} + i{:.2}", cp.re, f32::abs(cp.im));
    }
}

fn complex_abs(cp: & ComplexT) -> f32 {
    let module: f32 = f32::sqrt(cp.re * cp.re + cp.im * cp.im);
    module
}

