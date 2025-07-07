struct Student {
    name: String,
    surname: String,
    index: i32,
}

fn show(p: & Student) {
    println!("My name is: {} {}, and my index is: {}", p.name, p.surname, p.index);
}

fn read(p: &mut Student) -> &mut Student {
    let mut input: String = String::new();

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    p.name = input.trim().parse().expect("Incorrect parsing");

    input.clear();

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    p.surname = input.trim().parse().expect("Incorrect parsing");

    input.clear();

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    p.index = input.trim().parse().expect("Incorrect parsing");

    p
}

fn main() {
    let mut p = Student {
        name: String::new(),
        surname: String::new(),
        index: 0,
    };

    println!("Enter: ");
    show(read(&mut p));
}
