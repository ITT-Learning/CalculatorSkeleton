const HistoryEntry = ({ data, handleDelete, recallHistory }) =>
{
    const { equation, result } = data;
    return (
        <div className="d-flex justify-content-between no-select selectable p-2" title={`Recall this equation: (${data.equation})`} onClick={recallHistory}>
            <div className="d-flex flex-column ms-4">
                <span className="text-info fs-5">= {result}</span>
                <span className="text-muted fs-6 ps-3">{equation}</span>
            </div>
            <button className="btn btn-danger" onClick={(event) => { event.stopPropagation(); handleDelete(); }}>Delete</button>
        </div>
    );
}
 
export default HistoryEntry;