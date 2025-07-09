#[derive(Default)]
pub struct ArrayT {
    pub array: Vec<i32>,
    pub size: usize,
    pub capacity: usize,
}

pub fn array_create(a: &mut ArrayT, size: usize) {
    a.array = vec![0; size];
    a.size = 0;
    a.capacity = size;
}

pub fn array_push_back(a: &mut ArrayT, value: i32) -> i32 {
    if a.size > a.capacity || a.capacity <= 0 {
        return 1;
    }

    if a.size == a.capacity {
        return 2;
    }

    a.array[a.size] = value;
    a.size += 1;

    0
}

pub fn array_display(a: & ArrayT) {
    if a.size > a.capacity || a.capacity <= 0 {
        return;
    }
    for i in 0..a.size {
        print!("{} ", a.array[i]);
    }
    println!();
}

pub fn array_copy(a: & ArrayT, b: &mut ArrayT) {
    array_create(b, a.size);

    for i in 0..a.size {
        b.array[i] = a.array[i];
    }
    b.size = a.size;
    b.capacity = a.capacity;
}

pub fn array_separate(a: & ArrayT, even: &mut ArrayT, odd: &mut ArrayT) -> i32 {
    let mut for_odd: usize = 0;
    let mut for_even: usize = 0;

    for i in 0..a.size {
        if a.array[i] % 2 != 0 {
            for_odd += 1;
        }
        else {
            for_even += 1;
        }
    }

    even.size = for_even;
    odd.size = for_odd;

    if even.size == 0 && odd.size == 0 {
        return 1;
    }
    else if odd.size > 0 && even.size == 0 {
        array_copy(a, odd);
        return 0;
    }
    else if even.size > 0 && odd.size == 0 {
        array_copy(a, even);
        return 0;
    }
    else {
        array_create(odd, odd.size);
        array_create(even, even.size);

        odd.size = 0;
        even.size = 0;

        for i in 0..a.size {
            if a.array[i] % 2 == 0 {
                even.array[even.size] = a.array[i];
                even.size += 1;
            }
            else {
                odd.array[odd.size] = a.array[i];
                odd.size += 1;
            }
        }

        odd.capacity = odd.size;
        even.capacity = even.capacity;
    }

    3
}
