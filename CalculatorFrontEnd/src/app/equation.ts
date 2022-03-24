export interface Equation {
    id: number | null;
    asString: string | null;
    value: number | null;
    variables: EquationVariable[];
}

export interface EquationVariable {
    variable: string;
    value: number | null;
}
