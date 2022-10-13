const HistoryEntry = ({ data, handleDelete }) =>
{
    const { equation, result } = data;
    return (
        <>
        <div className="d-flex justify-content-between">
            <div className="d-flex flex-column ms-4">
                <span className="text-info fs-5">= {result}</span>
                <span className="text-muted fs-6 ps-3">{equation}</span>
            </div>
            <button className="btn btn-danger" onClick={handleDelete}>Delete</button>
        </div>
        <hr className="border-5 border-light" />
        </>
    );
}
 
export default HistoryEntry;