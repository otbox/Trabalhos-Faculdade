import { useQuery } from "@apollo/client"
import { DeleteUserButton } from "./components/DeleteUserButton"
import { EditUserDialog } from "./components/EditUserDialog"
import { IUser } from "./App"
import { QUERY_ALL_USERS } from "./schema/schema"

export function RenderUsers(){

    const {loading, error, data} = useQuery(QUERY_ALL_USERS)

    if (loading){
        console.log("loading...")
    } 

    if (error){
        console.log("erro ao buscar")
    }

    return (
        <>
            <div style={ { display: "flex", width: "100%", flexWrap: "wrap", justifyContent: "center"
            } }>
                { data &&
                    data.users.map((user: IUser) => {
                        return <div key={user.username} style={ { display: "flex", flexDirection: "column", width: "400px", margin: "10px", padding: "20px", border: "1px solid mediumvioletred", borderRadius: "5px" } }>
                            {
                                Object.entries(user).map(([key, value]) => {
                                    console.log(key, value)
                                    return <div 
                                        style={ { display: "flex", justifyContent: "space-between" } }>
                                            <p>{key}</p> <p>{String(value)}</p></div>
                                })
                            }

                            <DeleteUserButton userId={Number(user.id)}/>
                            <EditUserDialog username={user.username} userId={Number(user.id)}/>
                        </div>
                    })
                }
            </div>
        </>
    )
}