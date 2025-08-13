#[derive(Default)]
struct ComplexT {
    re: f32,
    im: f32,
}

fn main() {
    let mut err: i32;

    let mut first: ComplexT = Default::default();
    println!("Enter: ");
    err = read(&mut first);
    if err != 0 {
        panic!("Error");
    }

    let mut second: ComplexT = Default::default();
    println!("Enter: ");
    err = read(&mut second);
    if err != 0 {
        panic!("Error");
    }

    let module: f32 = complex_abs(&first);
    if module < 0.0 {
        panic!("Error");
    }

    let mut result: ComplexT = Default::default();

    add(&first, &second, &mut result);
    show(&result);

    subtract(&first, &second, &mut result);
    show(&result);

    multiply(&first, &second, &mut result);
    show(&result);

    err = divide(&first, &second, &mut result);
    if err == 2 {
        panic!("Error");
    }
    show(&result);
}

fn read(cp: &mut ComplexT) -> i32 {
    let mut input: String = String::new();

    std::io::stdin().read_line(&mut input).expect("Error");

    let input = input.trim();
    let (re, oper, im) = if let Some(pos) = input.find('+') {
        let re_str = &input[..pos];
        let im_str = &input[pos + 1..];
        (re_str, '+', im_str)
    } else if let Some(pos) = input.find('-') {
        let re_str = &input[..pos];
        let im_str = &input[pos + 1..];
        (re_str, '-', im_str)
    } else {
        panic!("Error");
    };

    let re: f32 = match re.parse() {
        Ok(num) => num,
        Err(_) => {
            panic!("Error");
        }
    };

    let mut im: f32 = match im.parse() {
        Ok(num) => num,
        Err(_) => {
            panic!("Error");
        }
    };

    if oper == '-' {
        im = -1.0 * im;
        set(cp, re, im);
    } else if oper == '+' {
        set(cp, re, im);
    }
    else {
        return 1;
    }

    0
}
fn complex_abs(cp: & ComplexT) -> f32 {
    if cp.re == 0.0 && cp.im == 0.0 {
        return -1.0;
    }
    let module: f32 = f32::sqrt(cp.re * cp.re + cp.im * cp.im);
    module
}
fn show(cp: & ComplexT) {
    if cp.im < 0.0 {
        println!("{:.2} - i{:.2}", cp.re, f32::abs(cp.im));
    }
    else {
        println!("{:.2} + i{:.2}", cp.re, f32::abs(cp.im));
    }
}
fn set(cp: &mut ComplexT, re: f32, im: f32) -> &mut ComplexT {
    cp.re = re;
    cp.im = im;

    cp
}

fn add(first: & ComplexT, second: & ComplexT, result: &mut ComplexT) -> i32 {
    result.re = first.re + second.re;
    result.im = result.im + result.im;
    0
}
fn subtract(first: & ComplexT, second: & ComplexT, result: &mut ComplexT) -> i32 {
    result.re = first.re - second.re;
    result.im = result.im - result.im;
    0
}
fn multiply(first: & ComplexT, second: & ComplexT, result: &mut ComplexT) -> i32 {
    result.re = first.re * second.re - first.im * second.im;
    result.im = first.re * second.im + first.im * second.re;
    0
}
fn divide(first: & ComplexT, second: & ComplexT, result: &mut ComplexT) -> i32 {
    let some_shit_idk_help_me: f32 = second.re * second.re + second.im * second.im;
    if some_shit_idk_help_me <= 0.0 {
        return 2;
    }

    result.re = (first.re * second.re + first.im * second.im) / some_shit_idk_help_me;
    result.im = (first.im * second.re - first.re * second.im) / some_shit_idk_help_me;
    0
}
