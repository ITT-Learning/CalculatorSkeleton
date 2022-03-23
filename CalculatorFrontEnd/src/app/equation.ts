export interface Equation {
    id: number | null;
    asString: string | null;
    value: number | null;
    variables: Map<string, number> | null;
}