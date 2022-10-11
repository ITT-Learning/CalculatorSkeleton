const VariableInput = ({ name, value, handleChange }) =>
{
    return (
        <div className="d-flex flex-column align-items-start mx-5 mb-3">
            <span className="text-light pe-4 mb-1 fs-3 fst-italic">{name}: </span>
            <label htmlFor={name} className="visually-hidden">Variable {name}</label>
            <input type="text" name={name} className="form-control fs-3" value={value} onChange={handleChange} />
        </div>
    );
}
 
export default VariableInput;